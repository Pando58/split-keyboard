{ pkgs ? import <nixpkgs> {} }: let
in pkgs.mkShell {
	# nativeBuildInputs = with pkgs; [];

	buildInputs = with pkgs; [
		platformio
		# platformio-core
		# udev
	];
}
/* in (pkgs.buildFHSEnv {
	name = "kbd-tests";

	targetPkgs = pkgs: (with pkgs; [
		platformio
		openocd
		udev
	]);

	# runScript = "fish";
		  runScript = "env LD_LIBRARY_PATH= bash";

}).env */
