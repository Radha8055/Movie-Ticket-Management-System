let selectedMovie = "";
let ticketPrice = 0;

function selectMovie(movieName, price) {

    selectedMovie = movieName;
    ticketPrice = price;

    document.getElementById("movie").value = movieName;
    document.getElementById("price").value = "₹" + price;

    calculateTotal();

    document.querySelector(".booking-box").scrollIntoView({
        behavior: "smooth"
    });
}

function calculateTotal() {

    let quantity = parseInt(
        document.getElementById("quantity").value
    );

    if (isNaN(quantity) || quantity < 1) {
        quantity = 1;
    }

    let total = ticketPrice * quantity;

    document.getElementById("total").innerText = total;
}

function bookTicket() {

    if (selectedMovie === "") {
        alert("Please select a movie first!");
        return;
    }

    let quantity = parseInt(
        document.getElementById("quantity").value
    );

    let seat = document.getElementById("seat").value;

    let payment = document.getElementById("payment").value;

    let total = ticketPrice * quantity;

    let bookingId =
        "MT" + Math.floor(100000 + Math.random() * 900000);

    let receipt = document.getElementById("receipt");

    receipt.style.display = "block";

    receipt.innerHTML = `
        <h2>🎟️ Booking Confirmed</h2>

        <p><strong>Booking ID:</strong> ${bookingId}</p>

        <p><strong>Movie:</strong> ${selectedMovie}</p>

        <p><strong>Ticket Price:</strong> ₹${ticketPrice}</p>

        <p><strong>Number of Tickets:</strong> ${quantity}</p>

        <p><strong>Seat:</strong> ${seat}</p>

        <p><strong>Payment:</strong> ${payment}</p>

        <p><strong>Total Amount:</strong> ₹${total}</p>

        <hr>

        <p><strong>Thank you for booking!</strong></p>
    `;

    receipt.scrollIntoView({
        behavior: "smooth"
    });
}