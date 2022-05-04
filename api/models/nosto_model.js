const db = require('../database');

const nosto = {

    Saldo: function(postData,callback){
        return db.query(
            'call saldo_withdraw(?,?)',
            [postData.id1, postData.summa],
            callback
        );
    }
};
module.exports = nosto;