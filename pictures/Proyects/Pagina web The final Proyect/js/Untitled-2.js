// Array para almacenar los productos seleccionados
let productosSeleccionados = [];

// Función para agregar un producto al carrito
function agregarProducto(categoria, precio, imagenUrl, procesadoresCompatibles) {
    // Verificar si ya existe un producto de esa categoría en el carrito
    const index = productosSeleccionados.findIndex((producto) => producto.categoria === categoria);

    if (index !== -1) {
        // Si ya existe, mostrar advertencia y no agregar el producto
        alert(`Ya has seleccionado un producto de la categoría ${categoria}. Solo puedes seleccionar uno.`);
        return;
    } else {
        // Si no existe, agregarlo al carrito
        productosSeleccionados.push({
            categoria: categoria,
            precio: precio,
            imagen: imagenUrl,
            procesadoresCompatibles: procesadoresCompatibles, // Agregar la compatibilidad con procesadores
        });
        actualizarCarrito();
    }
}

// Función para eliminar un producto del carrito
function eliminarProducto(categoria) {
    productosSeleccionados = productosSeleccionados.filter((producto) => producto.categoria !== categoria);
    actualizarCarrito();
}

// Función para vaciar el carrito
function vaciarCarrito() {
    productosSeleccionados = [];
    actualizarCarrito();
}

// Función para actualizar la lista de productos seleccionados y el monto total
function actualizarCarrito() {
    const listaProductos = document.getElementById("carrito-lista");
    const totalElement = document.getElementById("total-carrito");
    listaProductos.innerHTML = "";
    let total = 0;

    productosSeleccionados.forEach((producto) => {
        const listItem = document.createElement("li");
        listItem.textContent = `${producto.categoria}: $${producto.precio}`;
        const eliminarBtn = document.createElement("button");
        eliminarBtn.textContent = "Eliminar";
        eliminarBtn.addEventListener("click", () => {
            eliminarProducto(producto.categoria);
        });
        listItem.appendChild(eliminarBtn);
        listaProductos.appendChild(listItem);
        total += producto.precio;
    });

    totalElement.textContent = `Total: $${total.toFixed(2)}`;
}

// Función para redirigir a la página de resumen de compra
function irAResumen() {
    if (productosSeleccionados.length === 0) {
        alert("El carrito de compra está vacío. Agrega productos antes de realizar el pago.");
    } else {
        // Crear un resumen de compra en formato JSON para enviar a la página de resumen
        const resumenCompra = JSON.stringify(productosSeleccionados);

        // Redirigir a la página de resumen y enviar los datos en la URL
        window.location.href = `resumen%20de%20compra.html?productos=${encodeURIComponent(resumenCompra)}`;
    }
}
