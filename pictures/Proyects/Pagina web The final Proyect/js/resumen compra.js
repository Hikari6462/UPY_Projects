document.addEventListener("DOMContentLoaded", function () {
    // Obtener los datos de los productos seleccionados de la URL
    const urlParams = new URLSearchParams(window.location.search);
    const productosJSON = urlParams.get("productos");
    const productosSeleccionados = JSON.parse(decodeURIComponent(productosJSON));

    // Obtener el formulario y agregar un evento de envío
    const userForm = document.getElementById("user-form");
    userForm.addEventListener("submit", function (event) {
        event.preventDefault();
        const formData = new FormData(userForm);
        const userData = Object.fromEntries(formData.entries());

        // Agregar los datos del usuario al resumen
        mostrarResumen(productosSeleccionados, userData);

        // Redireccionar a la página de agradecimiento después de unos segundos
        setTimeout(function () {
            window.location.href = "Agradecimiento.html";
        }, 5000); // Cambiar el tiempo en milisegundos (5 segundos en este caso)
    });

    // Función para mostrar el resumen de los productos seleccionados
    function mostrarResumen(productosSeleccionados, userData) {
        const resumenLista = document.getElementById("resumen-lista");
        resumenLista.innerHTML = "";

        productosSeleccionados.forEach((producto) => {
            const listItem = document.createElement("li");
            listItem.textContent = `${producto.categoria}: $${producto.precio}`;
            resumenLista.appendChild(listItem);
        });

        // Mostrar los datos del usuario en el resumen
        const datosUsuario = document.createElement("div");
        datosUsuario.innerHTML = `
            <h2>Datos del Usuario</h2>
            <p><strong>Nombre:</strong> ${userData.nombre}</p>
            <p><strong>Email:</strong> ${userData.email}</p>
            <p><strong>Dirección:</strong> ${userData.direccion}</p>
            <p><strong>Teléfono:</strong> ${userData.telefono}</p>
        `;
        resumenLista.appendChild(datosUsuario);
    }
});