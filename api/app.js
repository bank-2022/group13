var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

const helmet = require('helmet');
const cors = require('cors');

var indexRouter = require('./routes/index');
var asiakasRouter = require('./routes/asiakas');
var tiliRouter = require('./routes/tili');
var tilitapahtumaRouter = require('./routes/tilitapahtuma');
var nostoRouter = require ('./routes/nosto');
var korttiRouter = require ('./routes/kortti');
var saldoRouter = require ('./routes/saldo');
var kirjautuminenRouter = require ('./routes/kirjautuminen');

var app = express();

app.use(helmet());
app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtuma', tilitapahtumaRouter);
app.use('/nosto', nostoRouter);
app.use('/kortti', korttiRouter);
app.use('/Saldo', saldoRouter);
app.use('/kirjautuminen', kirjautuminenRouter);



module.exports = app;
