$(document).ready(() => {
	$("form").submit((e) => {
		e.preventDefault()
		let manuf = $("#manufacturer").val()
		let model = $("#model").val()
		let year = $("#year").val()
		let color = $("#color").val()
		let seating = $("#seating").val()
		let cubic = $("#cubic").val()
		let fuel = $("#fuel option:selected").text()
		let car = {
			manufacturer: manuf,
			model: model,
			year: year,
			fuelType: fuel,
			color: color,
			seatingCapacity: seating,
			cubicCapacity: cubic
		}
		console.log("Car: ", JSON.stringify(car, '\t', 2))
	})
})
