const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where asiakasID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (asiakasID,nimi,lähiosoite,puhelinnumero) values(?,?,?,?)',
      [asiakas.asiakasID, asiakas.nimi, asiakas.lähiosoite, asiakas.puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where asiakasID=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set asiakasID=?, nimi=?,lähiosoite=?, puhelinnumero=?, where asiakasID=?',
      //'update asiakas set asiakasID=? \n nimi=? \n, lähiosoite=? \n puhelinnumero=? \n where asiakasID=?',
      [asiakas.asiakasID,  asiakas.nimi, asiakas.lähiosoite, asiakas.puhelinnumero],
      callback
    );
  }
};
module.exports = asiakas;
