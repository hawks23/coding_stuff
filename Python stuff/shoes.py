#!/bin/python3

class Shoes:
    def __inti__(self,name,price):
        self.name = name
        self.price = price
    
    def budget_check(self,budget):
        if not isinstance(budget,(int,float)):
            print("Invalid Entry. Please enter a number")

    def change(self,budget):
        return(budget - self.price)
    
    def buy(self,budget):
        self.budget_check(budget)

        if budget >= self.price:
            print("You can buy some " + self.name)
            if budget == self.price:
                print("You have exactly enough money to buy " + self.name)

            else:
                print("You can buy " + self.name + " and have $" + str(change(budget)) + " money left\n")

            exit("\nThe program has ended\n")