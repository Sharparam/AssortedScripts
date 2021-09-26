def l(default, *colors)
  Hash[colors.map { |c| [c, !default]}].tap { |h| h.default = default }
end

def wl(*colors); l false, *colors; end
def bl(*colors); l true, *colors; end

CONFIG = {
  white: bl(:white, :black),
  red: wl(:green),
  black: bl(:white, :green, :orange),
  orange: wl(:red, :black),
  green: wl(:orange, :white),
  purple: bl(:purple, :green, :orange, :white)
}.freeze

state = nil

STDIN.each_line do |line|
  color = line.strip.to_sym
  abort "Boom" if state && !state[color]
  state = CONFIG[color]
end

puts "Bomb defused"
