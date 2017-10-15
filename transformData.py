#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 14 16:01:00 2017

@author: david
"""

import pandas as pd
import os
import json
import datetime


os.chdir('/home/david/Documents/Hack17')

#def 

sint = pd.read_csv('sintetic.log', names = ['S1', 'S2', 'S3', 'S4', 'S5', 'S6', 'Time'])

people = pd.read_csv('people.log', names = ['People', 'Time'])

#for i in range(len(sint)):
#    print sint.iloc[i,:]



sint = sint.dropna()
sint = sint.reset_index(drop = True); sint
people = people.dropna()
people = people.iloc[1:,:]
people = people.reset_index(drop = True); people

sint
def createTotalList(dataFrame):
    totalList = []
    for i in range(len(dataFrame)):
        rowList = []
        for j in range(5):
           dic = {"value": int(dataFrame.iloc[i, j]), "timestamp": dataFrame.iloc[i, 6]}
           rowList.append(dic)
        rowDict = {"observations": rowList}
        totalList.append(rowDict)
    return totalList



def timeFromMs(ms):
    secs = ms/1000.0
    minutes = secs/60; rem_secs = secs%60
    hours = minutes/60; rem_mins = minutes%60
    days = hours/24; rem_hours = days%24
    totalDay = 14+days; totalMonth = 10; totalYear = 2017
    totalHour = rem_hours+18; total_min = rem_mins+13; total_sec = rem_secs
    return str(int(round(totalDay)))+'/'+str(int(round(totalMonth)))+'/'+str(int(round(totalYear)))+'T'+str(int(round(totalHour)))+':'+str(int(round(total_min)))+':'+str(int(round(total_sec))).zfill(2)   

def createTotalColumn(dataFrame):
    fileCounter = 0
    for j in range(6):
        columnList = []
        for i in range(len(dataFrame)):    
            timeMs = dataFrame.iloc[i, 6]
            temps = timeFromMs(timeMs)
            dic = {"value": int(dataFrame.iloc[i, j]), "timestamp": temps}
            columnList.append(dic)
            if (i+1)%100 == 0: 
                columnDict = {"sensor": 'S'+str(j),"observations": columnList}
                columnList = []
                saveDict = {"sensors": [columnDict]}
                with open('./JSONS/data'+str(fileCounter)+'.txt', 'w') as outfile:
                    json.dump(saveDict, outfile)
                fileCounter+=1

def createTotalPeople(dataFrame):
    columnList = []
    for i in range(len(dataFrame)):    
        timeMs = int(dataFrame.iloc[i, 1])
        temps = timeFromMs(timeMs)
        dic = {"value": int(dataFrame.iloc[i, 0]), "timestamp": temps}
        columnList.append(dic)
        columnDict = {"sensor": 'PFlow0',"observations": columnList}
        saveDict = {"sensors": [columnDict]}
        with open('./JSONS/dataPeople.txt', 'w') as outfile:
            json.dump(saveDict, outfile)
                
createTotalColumn(sint)


int(people.iloc[2,0])
createTotalPeople(people)

#with open("./JSONS/data0.txt") as arxiu:
#    data = json.load(arxiu)

#os.system('curl --request PUT -d data -H "IDENTITY_KEY: d7fb75121ebfeed01f0d1c84b47a5a1aab0c890c35933cba4f18c1441fab6cbb" https://api.thingtia.cloud/data/prov1prov/')
