open Bip39;
open Hdkey;

type fromType =
  | Mnemonic
  | Seed
  | Xpub
  | Xpriv;

let emptyWallet: Types.wallet = {coin: "", derivePath: "", mnemonic: None, seed: None, xpriv: None, xpub: None};

let createWallet = (~from: fromType, ~value: string, ~path: string) =>
  switch (from) {
  | Mnemonic =>
    let rootnode = value |> mnemonicToSeedHex |> fromMasterSeed;
    let node = derive(rootnode, path);
    {
      ...emptyWallet,
      mnemonic: Some(value),
      seed: Some(value |> mnemonicToSeedHex),
      xpriv: Some(node##privateExtendedKey),
      xpub: Some(node##publicExtendedKey),
    };
  | Seed =>
    let rootnode = value |> fromMasterSeed;
    let node = derive(rootnode, path);
    {
      ...emptyWallet,
      seed: Some(value),
      xpriv: Some(node##privateExtendedKey),
      xpub: Some(node##publicExtendedKey),
    };
  | Xpriv => {...emptyWallet, xpriv: Some(value), xpub: Some(fromExtendedKey(value)##publicExtendedKey)}
  | Xpub => {...emptyWallet, xpub: Some(value)}
  };

let myWallet = createWallet(~from=Mnemonic, ~value=generateMnemonic(), ~path="m/44'/0'/0'/0/0");