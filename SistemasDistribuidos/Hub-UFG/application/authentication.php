<?php

require('functions.php');

//Inicia a sessão
session_start();

$login_input = $_POST['curador_login'];
$senha_input = $_POST['curador_senha'];

valida_usuario($login_input, $senha_input);

?>