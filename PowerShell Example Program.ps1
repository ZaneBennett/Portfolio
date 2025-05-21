$array = New-Object 'object[,]' 3,3
$array[0, 0] = "Al-Khwarizmi"
$array[0, 1] = "c. 780"
$array[0, 2] =  1328
$array[1, 0] = "Charles Babbage"
$array[1, 1] = "12/26/1791"
$array[1, 2] = 3819
$array[2, 0] = "Ada Lovelace"
$array[2, 1] = "12/10/1815"
$array[2, 2] = 1413

for($i = 0; $i -lt 3; $i++)
{
    [Environment]::NewLine
    Write-Host "Name: " $array[$i, 0]
    Write-Host "Date of Birth: " $array[$i, 1]
    Write-Host "ID Number: " $array[$i, 2]
}