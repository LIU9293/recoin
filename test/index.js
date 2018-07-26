const recoin = require('recoin')

describe('export many utils function from other librarys', () => {
  const randomSeed = recoin.randomSeed()
  const mnemonic = recoin.generateMnemonic()
  return { randomSeed, mnemonic }
})

describe('can create a lot of wallets for different coins', () => {
  const ethWallet = recoin.createWallet({
    coin: 'ETH',
    path: "m'/44'/60'/0'/0/0",
    seed: ''
  })
  return ethWallet
})
