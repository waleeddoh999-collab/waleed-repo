class car : 
    def __init__(self,model,year):
        self.model = model
        self.year = year 
    def showinfo(self):
        print (f"{self.model} " )
        print (f"{self.year}" )
            



car1 = car("nesan",2020)
car1.showinfo()