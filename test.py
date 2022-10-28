from lib2to3.pgen2 import driver
from sys import last_traceback
from selenium import webdriver

driver = webdriver.Firefox()
driver.get('https://github.com')
