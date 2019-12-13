import React from 'react'
import Membro from './Membro'

export default props =>
    <div>
        <h1>Família {props.sobrenome}</h1>
        <Membro nome="Rafael" sobrenome={props.sobrenome} />
        <Membro nome="Daniela" sobrenome={props.sobrenome} />
        <Membro nome="Pedro" sobrenome={props.sobrenome} />
        <Membro nome="Anna" sobrenome={props.sobrenome} />
    </div>