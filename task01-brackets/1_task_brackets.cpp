#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
//коды ошибок
enum err_expr {
	error_success,      //нет ошибки
	error_none_str,     //строка пуста
	error_div_byzero,   //деление на нуль!
	error_parse_number, //ошибка при парсировании числа
	error_brackets          //ОШИБКА!
};
int    is_expr(const char* s);
double _calc(const char* s, const char** p, enum err_expr* e);
 
 
//вычисление мат-выражений из строки
double calc(char* s, enum err_expr* err){
	char* a, *b;
	enum  err_expr e = error_success;
	const char*    p = NULL;
	double         n = 0.0;
 
	if(*s && is_expr(s)){
		a = s;
		while(*a && !isspace(*a))
			++a;
		for(b = a; *a; *a = *(++b)){
			if(! isspace(*b))
				++a;
		}
 
		if(*s)
			n = _calc(s, &p, &e);
		else
			e = error_none_str;
	} else
		e = (*s) ? error_brackets : error_none_str;
 
	if(err != NULL)
		*err = e;
	return n;
}
 
 
int main(void){
	enum err_expr e;
	char          s[256];
	double        t, res;
 
	//пример 
	strcpy(s, "))22.22+2.21((" );
	res = calc(s, &e);
	switch(e){
	case error_success:
		printf("%lg\n\n", res);
		break;
	case error_none_str:
		puts("строка пуста");
		break;
	case error_div_byzero:
		puts("деление на 0!");
		break;
	case error_parse_number:
		puts("ошибка при парсировании числа");
		break;
	case error_brackets:
		puts("ОШИБКА!");
		break;
	}
	getchar();
	return 0;
}
 
//проверка скобок на правильность расстоновки
int is_expr(const char* s){
	int n = 0;
	for(; *s; ++s){
		if(*s == '(')
			++n;
		else if(*s == ')'){
			if(--n < 0)
				break;
		}
	}
	return (n == 0);
}
 
// рекурсивное вычисление мат-выражений из строки
double  _calc(const char* s, const char** p, enum err_expr* e){
	int    neg;
	char   c, c1;
	char*  i;
	const char* o;
	double k, v, n = 0.0;
 
	if((*s == '(') || (*s == '-' && *(s + 1) == '(')){
		neg = (*s == '-');
		n   = _calc(s + (1 + neg), &o, e);
		if(*e != error_success)
			return 0.0;
		s = o;
		if(neg)
			n = 0.0 - n;
	} else {
		n = strtod(s, &i);
		if(s == i){
			*e = error_parse_number;
			return 0.0;
		}
		s = i;
	}
 
	while(*s && (*s != ')')){
		c = *s++;
		if(! *s){
			*e = error_brackets;
			return 0.0;
		}
 
		if(*s == '('){
			k = _calc(s + 1, &o, e);
			if(*e != error_success)
				return 0.0;
			s = o;
		} else {
			k = strtod(s, &i);
			if(s == i){
				*e = error_parse_number;
				return 0.0;
			}
			s = i;
        }
 
		switch(c){
		case '*':
			n *= k;
			break;
		case '/':
			if(k == 0.0){
				*e = error_div_byzero;
				return 0.0;
			}
			n /= k;
			break;
		case '+':
		case '-':
 
			if((*s == '*') || (*s == '/')) {
				v = k;
				while(*s && (*s != ')')) {
					c1 = *s;
					if((c1 == '+') || (c1 == '-'))
						break;
					++s;
					if(*s == '('){
						k = _calc(s + 1, &o, e);
						if(*e != error_success)
							return 0.0;
						s = o;
					} else {
						    k = strtod(s, &i);
					        if(s == i){
					    	  *e = error_parse_number;
				    		  return 0.0;
						    }
			      	        s = i;
					}  	    
					if(c1 == '/') {
						if(k == 0.0){
							*e = error_div_byzero;
							return 0.0;
						}
						v /= k;
					} else if(c1 == '*')
						v *= k;
				}
				k = v;
			}
 
			if(c == '+')
				n += k;
			else if(c == '-')
				n -= k;
 
			if(*s == ')'){
				*p = s + 1;
				return n;
			}
			break;
		}
	}
 
	if(*s == ')')
		*p = s + 1;
	return n;
}