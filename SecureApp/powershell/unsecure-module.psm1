function Show-Calendar {
    #PSAvoidUsingComputerNameHardcoded
    Invoke-Command -ComputerName:"hardcode"

    # PSAvoidUsingConvertToSecureStringWithPlainText
    ConvertTo-SecureString -String "PlaceholderString" -AsPlainText
}

Export-ModuleMember -Function Show-Calendar