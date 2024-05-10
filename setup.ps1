#Requires -RunAsAdministrator
# Linked Files (Destination => Source)
$symlinks = @{
    "$HOME\qmk_firmware\keyboards\checkerboards\quark_lp\keymaps\gebs" = ".\checkerboards\quark_lp\keymaps\gebs"
    "$HOME\qmk_firmware\keyboards\crkbd\keymaps\gebs"                  = ".\crkbd\keymaps\gebs"
    "$HOME\qmk_firmware\keyboards\gmmk\pro\keymaps\gebs"               = ".\gmmk\pro\keymaps\gebs"
    "$HOME\qmk_firmware\keyboards\planck\keymaps\gebs"                 = ".\planck\keymaps\gebs"
    "$HOME\qmk_firmware\keyboards\xd75\keymaps\gebs"                   = ".\xd75\keymaps\gebs"
}

$qmk_path = "$HOME\qmk_firmware"

if (Test-Path -Path $qmk_path) {

    # Create Symbolic Links
    Write-Host "Creating Symbolic Links..."
    foreach ($symlink in $symlinks.GetEnumerator()) {
        Get-Item -Path $symlink.Key -ErrorAction SilentlyContinue | Remove-Item -Force -Recurse -ErrorAction SilentlyContinue
        New-Item -ItemType SymbolicLink -Path $symlink.Key -Target (Resolve-Path $symlink.Value) -Force | Out-Null
    }

}
}