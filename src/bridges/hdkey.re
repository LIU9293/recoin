/* came from JS class */
type hdnodeType = {
  .
  "publicExtendedKey": string,
  "privateExtendedKey": string,
};

/* some bindings for hdkey library */
[@bs.module "hdkey"] external fromMasterSeed : string => hdnodeType = "fromMasterSeed";
[@bs.module "hdkey"] external fromExtendedKey : string => hdnodeType = "fromExtendedKey";
[@bs.send] external derive : (hdnodeType, string) => hdnodeType = "derive";