from flask_restful import Resource

#Import DeviceModel
from models.device import DeviceModel

class DeviceList(Resource):
	def get(self):
		try:
			devices = DeviceModel.find_all()
		except:
			return {"error": "An error occured selecting the devices"}, 500 #internal server error
		if devices:
			return {'devices': [device.json() for device in devices]}
		return { "error" : "No devices connected to the network" }, 404