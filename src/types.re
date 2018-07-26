type coinType = Coin
  | Token;

type coin = {
  symbol: string,
  name: string,
  decimal: int,
  logo: string,
  _type: coinType,
};

type transaction = {
  fromAddress: string,
  toAddress: string,
  value: string,
  timestamp: int,
  coin: string,
};

type wallet = {
  coin: coin,
  transactions: list(transaction),
  name: string,
  hdpath: string,
  balance: int,
};
