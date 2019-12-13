import React from 'react'
import ReactDOM from 'react-dom'
//import PrimeiroComponente from './componentes/PrimeiroComponente'
//import {CompA, CompB as B} from './componentes/DoisComponentes'
//import MultiElementos from './componentes/MultiElementos'
//import FamiliaSilva from './componentes/FamiliaSilva'
//import Familia from './componentes/Familia'
//import Membro from './componentes/Membro'
//import ComponenteComFuncao from './componentes/ComponenteComFuncao'
//import Filho from './componentes/Filho'
//import Pai from './componentes/Pai'
//import ComponeteClasse from './componentes/ComponenteClasse'
//import Contador from './componentes/Contador'
import Hook from './componentes/Hooks'

const element = document.getElementById('root')
ReactDOM.render(
    <div>
        <Hook />
        {/*<Contador numero={0} />
        <ComponeteClasse valor="Sou um componente de classe" />
        <Pai />
        <ComponenteComFuncao />
        <Familia sobrenome="Pereira">
            <Membro nome="Andre"  />
            <Membro nome="Mariana" sobrenome="Pereira" />
        </Familia>
        <Familia sobrenome="Arruda">
            <Membro nome="Bia"  />
            <Membro nome="Gustavo" sobrenome="Arruda" />
        </Familia>*/}
        {/*<FamiliaSilva sobrenome="Silva" />
        <MultiElementos></MultiElementos>
        <PrimeiroComponente valor='Bom dia'></PrimeiroComponente>
        <CompA valor='Iae, sou A'></CompA>
        <B valor='B na area'></B>*/}
    </div>
    , element)