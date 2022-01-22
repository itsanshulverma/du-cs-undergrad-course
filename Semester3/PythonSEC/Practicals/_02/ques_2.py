
def calc(sale1, sale2, sale3, sale4):
    total_sales = sale1+sale2+sale3+sale4
    com_amt = 0 #Commission
    if total_sales >= 50000:
        com_amt = total_sales*0.05
    remarks = ""
    if total_sales >= 80000:
        remarks = "Excellent"
    elif total_sales >= 60000:
        remarks = "Good"
    elif total_sales >= 40000:
        remarks = "Average"
    elif total_sales < 40000:
        remarks = "Work Hard"

    return total_sales, com_amt, remarks

if __name__ == "__main__":
    sale1 = int(input("Enter the sales for week 1: "))
    sale2 = int(input("Enter the sales for week 2: "))
    sale3 = int(input("Enter the sales for week 3: "))
    sale4 = int(input("Enter the sales for week 4: "))
    t_sales, comm, remarks = calc(sale1, sale2, sale3, sale4)

    print("Total Sales: Rs.{:.2f}".format(t_sales))
    print("Commission: Rs.{:.2f}".format(comm))
    print("Remarks:", remarks)