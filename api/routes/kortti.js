const express = require('express');
const router = express.Router();
const asiakas = require('../models/kortti_model.js');

router.get('/:id?',
function(request, response){
    if(request.params.id){
        asiakas.getById(request.params.id, function(err, dbResult){
            if (err){
                response.json(err);
            } else{
                response.json(dbResult);
            }
        });
    } else{
        asiakas.getAll(function(err, dbResult){
            if (err){
                response.json(err);
            } else{
                response.json(dbResult);
            }
        });
    }
});


router.post('/', 
function(request, response) {
  asiakas.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:AsiakasID', 
function(request, response) {
  asiakas.delete(request.params.AsiakasID, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:AsiakasID', 
function(request, response) {
  asiakas.update(request.params.AsiakasID, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;