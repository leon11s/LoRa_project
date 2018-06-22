from db import db

class DeviceModel(db.Model):
	__tablename__ = 'devices'
	
	id = db.Column(db.Integer, primary_key = True)
	name = db.Column(db.String(80))
	
	def __init__(self, name):
		self.name = name
		
	def json(self):
		return {'id': self.id, 'name': self.name}
	
	#query methods
	
	@classmethod
	def find_by_name(cls, name):
		return cls.query.filter_by(name = name).first() 	
		
	@classmethod
	def find_all(cls):
		return cls.query.all()	
		
	def save_to_db(self):
		db.session.add(self)
		db.session.commit()
		
	def delete_from_db(self):
		db.session.delete(self)	
		db.session.commit()