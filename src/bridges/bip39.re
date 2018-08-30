[@bs.module "bip39"] external validateMnemonic : string => bool = "validateMnemonic";
[@bs.module "bip39"] external generateMnemonic : unit => string = "generateMnemonic";
[@bs.module "bip39"] external mnemonicToSeedHex : string => string = "mnemonicToSeedHex";