const db = require('../database');
const bcrypt = require('bcryptjs');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where AsiakasID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    
      bcrypt.hash(kortti.PIN,10,function(err,hash){
        return db.query(
      'insert into kortti (KorttiID,Korttinumero,PIN,AsiakasID,TiliID) values(?,?,?,?,?)',
      [kortti.korttiID, kortti.Korttinumero,hash, kortti.AsiakasID, kortti.TiliID],
      callback);});
      
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where TiliID=?', [id], callback);
  },
  update: function(id, kortti, callback) {

    bcrypt.hash(kortti.PIN,10,function(err,hash){
    return db.query(
      'update kortti set Korttinumero=?, PIN=?, where AsiakasID=?',
      [kortti.Korttinumero, hash, id],
      callback);});
  }
};
module.exports = kortti;