# REST API IoT Server

https://gist.github.com/iros/3426278

## Installation

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