import React, { useState, useEffect } from 'react'

export default props => {
    const [contador, setContador] = useState(100)
    const [status, setStatus] = useState('Par')

    useEffect(() => {
        contador % 2 === 0 ? setStatus('par') : setStatus('impar')
    })

    return (
        <div>
            <h1>{contador}</h1>
            <h2>{status}</h2>
            <button onClick={() => setContador(contador+1)}>Inc</button>
        </div>
    )
}