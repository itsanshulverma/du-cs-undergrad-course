import math

def calculate(side1, side2, side3):
    perimeter = 0
    area = 0
    # Check if input forms a triangle
    if side1 + side2 > side3 and side2 + side3 > side1 and side1 + side3 > side2:
        print("Given sides form a triangle.")
        perimeter = side1 + side2 + side3
        s = perimeter/2
        area = math.sqrt(s*(s-side1)*(s-side2)*(s-side3))
    else:
        print("ERR: Given sides does not form a triangle.")
        print("[Sum of two sides of a triangle should be greater than the third]")
        quit()
    return perimeter, area

if __name__ == "__main__":
    side1 = float(input("Enter the length of side 1: "))
    side2 = float(input("Enter the length of side 2: "))
    side3 = float(input("Enter the length of side 3: "))
    perimeter, area = calculate(side1, side2, side3)
    print("Perimeter: {} units".format(perimeter))
    print("Area: {:.3f} sq. units".format(area))