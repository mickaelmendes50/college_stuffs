import React, { Component } from 'react'

export default class Contador extends Component {

    state = {
        numero: this.props.numero
    }

    maisUm = () => {
        this.setState({ numero: this.state.numero + 1 })
        //this.state.numero++
    }

    menosUm = () => {
        this.setState({ numero: this.state.numero - 1 })
        //this.state.numero++
    }

    alterarNumero = (diferenca) => {
        this.setState({ numero: this.state.numero + diferenca })
    }

    render() {
        return (
            <div>
                <div>Número: {this.state.numero}</div>
                <button onClick={this.maisUm}>Increase</button>
                <button onClick={this.menosUm}>Decrease</button>
                <button onClick={() => this.alterarNumero(10)}>Increase 10</button>
                <button onClick={() => this.alterarNumero(-10)}>Decrease 10</button>
            </div>
        )
    }
}

    // Metodo this.
    // Solucao 1 - método bind
    /*constructor(props) {
        super(props)
        this.maisUm = this.maisUm.bind(this)
    }*/

    // Solucao 2 - Função Arrow onClick
    // <button onClick={() => this.maisUm()}>Increase</button>

    // Solucao 3 - Função Arrow
    /*maisUm = () => {
        this.props.numero++
    }*/