// Array para almacenar los productos seleccionados
let productosSeleccionados = [];

// Función para agregar un procesador al carrito
function agregarProcesador(procesador) {
    productosSeleccionados.push({
        categoria: "Procesador",
        nombre: procesador
    });
    alert(`Has agregado el procesador ${procesador} al carrito de compras.`);
}

// Función para redirigir a la página de selección de piezas
function irASeleccionarPiezas() {
    if (productosSeleccionados.length === 0) {
        alert("Debes seleccionar un procesador antes de continuar.");
    } else {
        // Crear un resumen de compra en formato JSON para enviar a la página de selección de piezas
        const resumenCompra = JSON.stringify(productosSeleccionados);

        // Redirigir a la página de selección de piezas y enviar los datos en la URL
        window.location.href = `seleccionar_piezas.html?productos=${encodeURIComponent(resumenCompra)}`;
    }
}
