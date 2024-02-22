const botonMostrarFormulario = document.getElementById('mostrarFormulario');
const ventanaEmergente = document.getElementById('infob');
const formulario = document.getElementById('formulario');

botonMostrarFormulario.addEventListener('click', function () {
    ventanaEmergente.style.display = 'block';
});

ventanaEmergente.addEventListener('click', function (e) {
    if (e.target === ventanaEmergente) {
        ventanaEmergente.style.display = 'none';
    }
});


