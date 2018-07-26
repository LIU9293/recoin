open Bip39;
open Hdkey;

let mnemonic = generateMnemonic();
let seed = mnemonicToSeedHex(mnemonic);
let node = fromMasterSeed(seed);
let child = derive(node, ("m'/44'/60'/0'"));

Js.log (child##publicExtendedKey);
