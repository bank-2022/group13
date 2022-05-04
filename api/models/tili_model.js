const db = require('../database');

const tili = {
  getByID: function(id, callback) {
    return db.query('select * from tili where TiliID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (TiliID, Tilinumero, Saldo) values(?,?,?)',
      [tili.TiliID, tili.Tilinumero, tili.Saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where TiliID=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set Tilinumero=?, Saldo=? where TiliID=?',
      [id, tili.Tilinumero, tili.Saldo],
      callback
    );
  }
};
module.exports = tili;