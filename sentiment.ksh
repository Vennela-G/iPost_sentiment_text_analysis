AZURE_URL="az-text-analytics-br.cognitiveservices.azure.com"
SUBSCRIPTION_KEY="00124bb5c8104f45b0a5a7023e880f2b"
DATA_TEXT=$(cat << EOM
{ 
  "documents": [ 
    { \
      "language": "en", 
      "id": "1",
      "text": "${1}"
    }
  ]
}
EOM
)



OUTPUT=`curl  -s -X POST "https://${AZURE_URL}/text/analytics/v2.1/sentiment?showStats=false" \
-H "Content-Type: application/json" \
-H "Ocp-Apim-Subscription-Key: ${SUBSCRIPTION_KEY}" \
--data "${DATA_TEXT}"`

echo $OUTPUT
