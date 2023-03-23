<?php

    require('functions.php');

    $login_hubufg = 'curador2@gmail.com';
    $senha_hubufg = 'curador123';

    $novo_usuario = cadastra_novo_usuario($login_hubufg, $senha_hubufg);

    if($novo_usuario !== false){

        echo 'Usuário cadastrado!!!'.PHP_EOL;

    }else{

        echo 'Falha ao cadastrar Usuário!!!'.PHP_EOL;

    }

?>