vim.cmd.colorscheme "catppuccin-mocha"

vim.opt.nu = true
vim.opt.relativenumber = true

vim.api.nvim_set_keymap('n', '<C-U>', '<C-U>zz', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<C-D>', '<C-D>zz', { noremap = true, silent = true })

vim.opt.tabstop = 2
vim.opt.softtabstop = 2
vim.opt.shiftwidth = 2
vim.opt.expandtab = true
vim.opt.smartindent = true

vim.opt.wrap = false

vim.opt.swapfile = false
vim.opt.backup = false
vim.opt.undodir = os.getenv("HOME") .. "/.vim/fndodir"
vim.opt.undofile = true

vim.opt.hlsearch = false
vim.opt.incsearch = true

vim.opt.termguicolors = true

vim.opt.scrolloff = 8
vim.opt.signcolumn = "yes"
vim.opt.isfname:append("@-@")

vim.opt.updatetime = 50
-- vim.opt.colorcolumn = "80"
vim.opt.fillchars = { eob = " " }

-- resizing splits
vim.api.nvim_set_keymap('n', '<leader>w>', ':vertical resize +10<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<leader>w<', ':vertical resize -10<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<leader>w+', ':resize +10<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<leader>w-', ':resize -10<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<leader>v', ':vsplit<CR>', { noremap = true, silent = true })

-- nav panes
vim.api.nvim_set_keymap('n', '<c-k>', ':wincmd k<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<c-j>', ':wincmd j<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<c-h>', ':wincmd h<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<c-l>', ':wincmd k<CR>', { noremap = true, silent = true })


vim.opt.wrap = true
vim.opt.breakindent = true
vim.opt.showbreak = ' \\'




-- Stop auto comments
vim.api.nvim_create_autocmd("BufEnter", {
    callback = function()
        vim.opt.formatoptions = vim.opt.formatoptions - { "c","r","o" }
    end,
})


local group = vim.api.nvim_create_augroup("YankHighlight", { clear = true })
vim.api.nvim_create_autocmd("TextYankPost", {
    group = group,
    callback = function()
        vim.highlight.on_yank({higroup="IncSearch", timeout=350})
    end,
})


vim.diagnostic.config({
  virtual_text = false
})

vim.o.updatetime = 250
vim.cmd [[autocmd CursorHold,CursorHoldI * lua vim.diagnostic.open_float(nil, {focus=false})]]

function ReloadConfig()
  dofile(vim.env.MYVIMRC)
  -- Add more files to source if needed
  dofile(vim.fn.expand("~/.config/nvim/init.lua"))
end

vim.api.nvim_set_keymap('n', '<leader>r', ':lua ReloadConfig()<CR>', { noremap = true, silent = true })
vim.filetype.add { pattern = { [".*/hypr/.*%.conf"] = "hyprlang" } }

-- wayland uses the '+' register whereas X11 uses the '*'. make '*' register work for wayland.
vim.g.clipboard = {
  name = "wl-clipboard with remapped *",
  copy = {
    ["+"] = "wl-copy",
    ["*"] = "wl-copy", -- mirror +
  },
  paste = {
    ["+"] = "wl-paste --no-newline",
    ["*"] = "wl-paste --no-newline", -- mirror +
  },
  cache_enabled = 0,
}
