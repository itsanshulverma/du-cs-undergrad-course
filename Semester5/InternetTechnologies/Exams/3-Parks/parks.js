const parks = [
	{name: "Jim Corbett National Park", state: "Uttarakhand", speciality: "Tigers"},
	{name: "Kaziranga National Park", state: "Assam", speciality: "Rhinos"},
	{name: "Asola Bhatti Wildlife Sanctuary", state: "Delhi", speciality: "Birds"},
	{name: "Gir National Park", state: "Gujarat", speciality: "Lion"}
]

let form = document.querySelector("form")
let valueEl = document.getElementById("value")

form.addEventListener('submit', (e) => {
	e.preventDefault();
	let index = document.getElementById("index").value
	let name = document.getElementById("name").value
	valueEl.innerHTML = "<br>"+parks[index][name]
})