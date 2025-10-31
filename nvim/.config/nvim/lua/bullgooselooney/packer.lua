-------------------------------------------------------------------------------
-- When you add a new plugin you have to do `:so` before running `:PackerSync'
--
-- The 'use' statements tell packer to download and manage these dependencies
-------------------------------------------------------------------------------

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)

  use({
    "olimorris/codecompanion.nvim",
    config = function()
      require("codecompanion").setup()
    end,
    requires = {
      "nvim-lua/plenary.nvim",
      "nvim-treesitter/nvim-treesitter",
    }
  })

  use {
    "zbirenbaum/copilot.lua",
    cmd = "Copilot",
    event = "InsertEnter",
    config = function()
      require("copilot").setup({})
    end,
  }

	-- Packer can manage itself
	use 'wbthomason/packer.nvim'

  use 'folke/which-key.nvim'

  -- Markdown live preview
  use 'ellisonleao/glow.nvim'

  -- vim-tmux-navigator
  use 'christoomey/vim-tmux-navigator'

  -- theme
  use { "catppuccin/nvim", as = "catppuccin" }

	-- Telescope
	use {
		'nvim-telescope/telescope.nvim', tag = '0.1.6',
		requires = { {'nvim-lua/plenary.nvim'} }
	}

	-- you can translate `Plug` (another package manager)statements like this
	-- Old: Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
	use ( 'nvim-treesitter/nvim-treesitter', {run = ':TSUpdate'})
	use ( 'mbbill/undotree' )
	use ( 'tpope/vim-fugitive' )
    use ( 'theprimeagen/harpoon')
    use ( 'airblade/vim-gitgutter' )

    -- Cool welcome screen
    use {
        'goolord/alpha-nvim',
        config = function ()
            require'alpha'.setup(require'alpha.themes.dashboard'.config)
        end
    }

    -- lua line ()
    use {
        'nvim-lualine/lualine.nvim',
        requires = { 'nvim-tree/nvim-web-devicons', opt = true }
    }

	-- LSP
	use {
		'VonHeikemen/lsp-zero.nvim',
		branch = 'v3.x',
		requires = {
			{'williamboman/mason.nvim'},
			{'williamboman/mason-lspconfig.nvim'},
			{'neovim/nvim-lspconfig'},
			{'hrsh7th/nvim-cmp'},
			{'hrsh7th/cmp-nvim-lsp'},
			{'L3MON4D3/LuaSnip'},
		}
	}

    -- Comment with gcc
    use {
        'numToStr/Comment.nvim',
        config = function()
            require('Comment').setup()
        end
    }

    use {
        "windwp/nvim-autopairs",
        event = "InsertEnter",
        config = function()
            require("nvim-autopairs").setup {}
        end
    }

end)
