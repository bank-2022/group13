const express = require('express');
const router = express.Router();
const nosto = require('../models/nosto_model.js');

router.post('/', function(request, response){
    nosto.debit(request.body, function(err, dbResult){
        if(err){
            response.json(false);
        }
        else{
            response.json(true);
        }
    })
}
);

module.exports = router;