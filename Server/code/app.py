from flask import Flask
from flask_restful import Api

#Import resources
from resources.device import DeviceList

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
#app.config['SQLALCHEMY_TRACK_NOTIFICATIONS'] = False
#app.secret_key = 'bob' #in production it's need to be secret and long

api = Api(app)

#Resources
api.add_resource(DeviceList, '/api/v1/devices')

if __name__ == '__main__':
	from db import db
	db.init_app(app)
	app.run(port = 5000, debug = True)