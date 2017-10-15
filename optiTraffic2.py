# -*- coding: utf-8 -*-
"""
Created on Sat Oct 14 10:37:07 2017

@author: Admin
"""

import numpy as np
import scipy as sc
import pandas as pd
from scipy.stats import poisson


mu = 40
randomPoiss = poisson.rvs(mu, size=24)
randomPoiss2 = poisson.rvs(1.5*mu, size=24)


biases = 10*np.array([10, 0, 0, 0, 0, 10, 30, 50, 80, 100, 70, 60, 50, 50, 50, 50, 80, 100, 80, 70, 60, 50, 40, 20])
biases2 = 10*np.array([20, 5, 0, 0, 0, 10, 30, 50, 80, 130, 50, 60, 50, 50, 40, 50, 80, 100, 80, 70, 60, 50, 40, 20])


peopleData = randomPoiss+biases
print(peopleData)

carsData = randomPoiss2+biases2

width_cars = 4.
v_car = 10.
width_peo = 8.
v_people = 1.

#tau_car = width_cars/v_car
#tau_peo = width_peo/(20*v_people)

#tau_car/tau_peo

def costFunction(variavs):
    t_peo = variavs[0]; t_car = variavs[1]
    num_cars = params[0]
    num_peo = params[1]
    return 1E6*(num_peo*num_cars)*(1/(t_peo**2+t_car**2))+num_peo*t_car**2+num_cars*t_peo**2

def costFunction2(variavs):
    return costAlpha(variavs)+max(costPeople(variavs), costCars(variavs))

def costAlpha(variavs):
    t_peo = variavs[0]; t_car = variavs[1]
    num_cars = params[0]
    num_peo = params[1]
    return 0.01*(num_peo*num_cars)**2*(1/(t_peo**2+t_car**2))

def costPeople(variavs):
    t_peo = variavs[0]; t_car = variavs[1]
    num_cars = params[0]
    num_peo = params[1]
    return num_cars*t_peo**2

def costCars(variavs):
    t_peo = variavs[0]; t_car = variavs[1]
    num_cars = params[0]
    num_peo = params[1]
    return num_peo*t_car**2

num_cars = carsData[4]
num_peo = peopleData[4]
params = [num_cars, num_peo]

num_cars
num_peo

costFunction([20., 20.])
bnds = ((10, None), (10, None))
optiVars = sc.optimize.minimize(costFunction2, x0=np.array([20., 20.]), method='SLSQP', bounds = bnds).x; optiVars

costPeople(optiVars)

costCars(optiVars)

costAlpha(optiVars)

costFunction(optiVars)


for i in range(24):
    num_cars = carsData[i]
    num_peo = peopleData[i]
    params = [num_cars, num_peo]
    bnds = ((10, None), (10, None))
    optiVars = sc.optimize.minimize(costFunction2, x0=np.array([20., 20.]), method='SLSQP', bounds = bnds).x; 
    print optiVars

    