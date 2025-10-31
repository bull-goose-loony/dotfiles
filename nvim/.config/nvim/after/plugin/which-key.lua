local wk = require("which-key")

wk.add({
  {"<leader>p", group = "Telescope" },
  {"<leader>pf", "<cmd>Telescope find_files<cr>", desc = "Fuzzy Find", mode = "n" },
  {"<leader>pg", "<cmd>Telescope git_files<cr>", desc = "Fuzzy Find in git repo", mode = "n" },

  {"<leader>f", group = "Find" },
  {"<leader>fg",  "<cmd>Telescope live_grep<cr>", desc = "grep", mode = "n"},
  {"<leader>fb",  "<cmd>Telescope buffers<cr>", desc = "buffers", mode = "n"}, 
  {"<leader>fh",  "<cmd>Telescope help_tags<cr>", desc = "help", mode = "n"}, 

  -- {"<leader>g", group = "" },
  -- {"<leader>gu",  "<cmd>Git push<cr>", desc = "push", mode = "n"},
  -- {"<leader>gl",  "<cmd>Git pull<cr>", desc = "pull", mode = "n"},
  -- {"<leader>ga",  "<cmd>Git add<cr>", desc = "add", mode = "n"},
  -- {"<leader>gt",  "<cmd>Git stash<cr>", desc = "stash", mode = "n"},
  -- {"<leader>gb",  "<cmd>Git blame<cr>", desc = "blame", mode = "n"},



})

-- {
--   "folke/which-key.nvim", event = "VeryLazy",
--   opts = {
--     -- your configuration comes here
--     -- or leave it empty to use the default settings
--     -- refer to the configuration section below
--   },
--   keys = {
--     {
--       "<leader>?",
--       function()
--         require("which-key").show({ global = false })
--       end,
--       desc = "Buffer Local Keymaps (which-key)",
--     },
--   },
-- }
