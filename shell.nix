{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  buildInputs = with pkgs; [
    raylib
  ];
  shellHook = ''
    # exported variables maybe...
  '';
}
