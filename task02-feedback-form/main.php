
<?php

$errors = [];

if (isset($_POST['email'])) {
    $domain = substr($_POST['email'], (strpos($_POST['email'], '@') + 1));
    if ($domain == 'gmail.com') {
        $errors[] = "Регистрация с доменом gmail.com запрещена!";
    }
}

if (empty($_POST['name'])){
    $errors['name'] = 'Не указаны ФИО.';
}
if (empty($_POST['tel'])){
    $errors['tel'] = 'Не указан телефон';
}
if (filter_var($_POST['email'], FILTER_VALIDATE_EMAIL) != $_POST['email']){
    $errors['email'] = 'Укажите корректный адрес электронной почты.';
}

if (!empty($errors)) {
    echo '<pre>';
    print_r($errors);
    echo '</pre>';
} else {
    echo 'Вы успешно зарегистрированы.';
}