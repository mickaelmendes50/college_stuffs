import React, { Component } from 'react'

export default class ComponeteClasse extends Component {
    render() {
        return (
            //<h1>Olá Classe</h1>
            <h2>{this.props.valor || 'Padrão'}</h2>
        )
    }
}