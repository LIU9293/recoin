type coinType =
  | Coin
  | Token;

type coin = {
  symbol: string,
  name: string,
  decimal: int,
  _type: coinType,
};

type txin = {
  address: string,
  amount: int,
  vin: int,
  txid: option(string),
};

type txout = {
  address: string,
  amount: int,
  vout: int,
  txid: option(string),
};

type transaction = {
  inputs: list(txin),
  outputs: list(txout),
  fee: option(int),
  gasprice: option(int),
  gaslimit: option(int),
  timestamp: int,
  memo: string,
  coin: string,
};

type wallet = {
  coin: string,
  mnemonic: option(string),
  seed: option(string),
  xpriv: option(string),
  xpub: option(string),
  derivePath: string,
};