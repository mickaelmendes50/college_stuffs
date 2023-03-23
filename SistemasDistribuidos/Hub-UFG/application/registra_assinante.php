<?php

    require('functions.php');

    $email = $_POST['email_assinante'];

    $registro = registra_assinante($email);

    if($registro !== false){

        header('location:../home/agradecimento.php');

    }else{

        header('location:../home/main.php');

    }

?>