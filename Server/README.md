# REST API IoT Server
https://docs.google.com/document/d/1HSQ3Fe77hnthw8hizqvXJU-qGEPHavMkctvCCadkVbY/edit?pli=1#heading=h.9t094e45sg90
https://gist.github.com/iros/3426278
https://developer.github.com/v3/
https://github.com/rgregg/rest-api-doc-template/blob/master/apis/template.md

## Installation
requirements
Flask - pip install flask 
pip install Flask-RESTful
pip install flask_sqlalchemy 

## Methods

### 1. login


### 2. get updates


## 3. 

**Show all devices names**
----
  <_Returns json data with the names of all devices in the network._>

* **URL**

  </api/v1/devices>

* **Method:**

  `GET`
  
*  **URL Params**

   None

* **Data Params**

  None

* **Success Response:**

  * **Code:** 200 <br />
    **Content:** `{ id : 5, name : "node01" }`
 
* **Error Response:**

  * **Code:** 404 NOT FOUND <br />
    **Content:** `{ error : "No devices connected to the network" }`
	
  OR

	Not implemented yet
	
  * **Code:** 401 UNAUTHORIZED <br />
    **Content:** `{ error : "You are unauthorized to make this request." }`

* **Sample Call:**

  ```Python
	import requests, time
	r = requests.get('http://url/api/v1/devices')
	print r.status_code
	print r.content
  ```