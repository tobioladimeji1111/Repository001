package unsafe

import (

	"crypto/md5"
	"crypto/rsa"
	"crypto/rand"
	"encoding/hex"
	"fmt"
	"database/sql"
)

var DB *sql.DB
var err error

type Profile struct{
	Uid int
	Name string
	City string
	PhoneNumber string
}

func badRSAkey() (*rsa.PrivateKey, error){
	return rsa.GenerateKey(rand.Reader, 5)
}

func(p *Profile) UnsafeQueryGetData(uid string)error{

	/* this funciton use to get data Profile from database with vulnerable query */

	getProfileSql := fmt.Sprintf(`SELECT p.user_id, p.full_name, p.city, p.phone_number 
								FROM Profile as p,Users as u 
								where p.user_id = u.id 
								and u.id=%s`,uid) //here is the vulnerable query
	rows, err := DB.Query(getProfileSql)
	if err != nil{
		return err  //this will return error query to clien hmmmm.
	}
	defer rows.Close()
	//var profile = Profile{}
	for rows.Next(){
		err = rows.Scan(&p.Uid,&p.Name,&p.City,&p.PhoneNumber)
		if err != nil{
			return err
		}
	}
	return nil
}



func Md5Sum(text string) string {
	hasher := md5.New()
	hasher.Write([]byte(text))
	return hex.EncodeToString(hasher.Sum(nil))
}