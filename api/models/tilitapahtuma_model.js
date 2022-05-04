const db = require('../database');
//const kortti = require('./kortti_model');

const tilitapahtuma = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtuma where TiliIDTapahtuma=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtuma', callback);
  },
  add: function(tilitapahtuma, callback) {
    return db.query(
      'insert into tilitapahtuma (TiliIDTapahtuma, Paivaus, Tapahtuma, Summa, TiliID, KorttiID,) values(?,?,?,?,?,?)',
      [tilitapahtuma.TiliIDTapahtuma, tilitapahtuma.Paivaus, tilitapahtuma.Tapahtuma,tilitapahtuma.Summa, tilitapahtuma.TiliID, tilitapahtuma.KorttiID],
      callback
    );
  },
  
  delete: function(id, callback) {
    return db.query('delete from tilitapahtuma where TiliIDTapahtuma=?', [id], callback);
  },
  update: function(id, tilitapahtuma, callback) {
    return db.query(
      'update tilitapahtuma set Paivaus=?, Tapahtuma=?, summa=?, TiliID=?, KorttiID, where TiliIDtapahtuma=?',
      [id, tilitapahtuma.Paivaus, tilitapahtuma.Tapahtuma, tilitapahtuma.Summa, tilitapahtuma.TiliID, tilitapahtuma.korttiID],
      callback
    );
  }
};
module.exports = tilitapahtuma;