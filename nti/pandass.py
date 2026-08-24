import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler,LabelEncoder,OrdinalEncoder
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score , mean_absolute_error , mean_squared_error


df = pd.read_csv('kc_house_data.csv')

df.drop(columns=['id'],inplace = True)


df['date']=pd.to_datetime(df['date'])
df["year"] = df["date"].dt.year
df.drop(columns=['date'],inplace = True)


x = df.drop(columns = ['price'])
y = df['price']

x_train,x_test,y_train,y_test = train_test_split(x,y,test_size = .2,random_state = 42,shuffle = True)

x_col=x.columns

poly = PolynomialFeatures(degree=4)
x_train_poly = poly.fit_transform(x_train)
x_test_poly = poly.transform(x_test)

scaler = StandardScaler()

x_train_poly = scaler.fit_transform(x_train_poly)
x_test_poly = scaler.transform(x_test_poly)

x_train = scaler.fit_transform(x_train)
x_test = scaler.transform(x_test)

lr = LinearRegression()

lr.fit(x_train,y_train)
lr.fit(x_train_poly,y_train)

y_pred_2 = lr.predict(x_test_poly)


print(r2_score(y_test,y_pred_2))
print(mean_absolute_error(y_test,y_pred_2))
print(mean_squared_error(y_test,y_pred_2))