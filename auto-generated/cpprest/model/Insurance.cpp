/**
 * BitMEX API
 * ## REST API for the BitMEX Trading Platform  [View Changelog](/app/apiChangelog)    #### Getting Started  Base URI: [https://www.bitmex.com/api/v1](/api/v1)  ##### Fetching Data  All REST endpoints are documented below. You can try out any query right from this interface.  Most table queries accept `count`, `start`, and `reverse` params. Set `reverse=true` to get rows newest-first.  Additional documentation regarding filters, timestamps, and authentication is available in [the main API documentation](/app/restAPI).  *All* table data is available via the [Websocket](/app/wsAPI). We highly recommend using the socket if you want to have the quickest possible data without being subject to ratelimits.  ##### Return Types  By default, all data is returned as JSON. Send `?_format=csv` to get CSV data or `?_format=xml` to get XML data.  ##### Trade Data Queries  *This is only a small subset of what is available, to get you started.*  Fill in the parameters and click the `Try it out!` button to try any of these queries.  * [Pricing Data](#!/Quote/Quote_get)  * [Trade Data](#!/Trade/Trade_get)  * [OrderBook Data](#!/OrderBook/OrderBook_getL2)  * [Settlement Data](#!/Settlement/Settlement_get)  * [Exchange Statistics](#!/Stats/Stats_history)  Every function of the BitMEX.com platform is exposed here and documented. Many more functions are available.  ##### Swagger Specification  [⇩ Download Swagger JSON](swagger.json)    ## All API Endpoints  Click to expand a section. 
 *
 * OpenAPI spec version: 1.2.0
 * Contact: support@bitmex.com
 *
 * NOTE: This class is auto generated by the swagger code generator 2.4.0-SNAPSHOT.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */



#include "Insurance.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

Insurance::Insurance()
{
    m_Currency = utility::conversions::to_string_t("");
    m_Timestamp = utility::datetime();
    m_WalletBalance = 0.0;
    m_WalletBalanceIsSet = false;
}

Insurance::~Insurance()
{
}

void Insurance::validate()
{
    // TODO: implement validation
}

web::json::value Insurance::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("currency")] = ModelBase::toJson(m_Currency);
    val[utility::conversions::to_string_t("timestamp")] = ModelBase::toJson(m_Timestamp);
    if(m_WalletBalanceIsSet)
    {
        val[utility::conversions::to_string_t("walletBalance")] = ModelBase::toJson(m_WalletBalance);
    }

    return val;
}

void Insurance::fromJson(web::json::value& val)
{
    setCurrency(ModelBase::stringFromJson(val[utility::conversions::to_string_t("currency")]));
    setTimestamp
    (ModelBase::dateFromJson(val[utility::conversions::to_string_t("timestamp")]));
    if(val.has_field(utility::conversions::to_string_t("walletBalance")))
    {
        setWalletBalance(ModelBase::doubleFromJson(val[utility::conversions::to_string_t("walletBalance")]));
    }
}

void Insurance::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("currency"), m_Currency));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("timestamp"), m_Timestamp));
    if(m_WalletBalanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("walletBalance"), m_WalletBalance));
    }
}

void Insurance::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setCurrency(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("currency"))));
    setTimestamp(ModelBase::dateFromHttpContent(multipart->getContent(utility::conversions::to_string_t("timestamp"))));
    if(multipart->hasContent(utility::conversions::to_string_t("walletBalance")))
    {
        setWalletBalance(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("walletBalance"))));
    }
}

utility::string_t Insurance::getCurrency() const
{
    return m_Currency;
}


void Insurance::setCurrency(utility::string_t value)
{
    m_Currency = value;
    
}
utility::datetime Insurance::getTimestamp() const
{
    return m_Timestamp;
}


void Insurance::setTimestamp(utility::datetime value)
{
    m_Timestamp = value;
    
}
double Insurance::getWalletBalance() const
{
    return m_WalletBalance;
}


void Insurance::setWalletBalance(double value)
{
    m_WalletBalance = value;
    m_WalletBalanceIsSet = true;
}
bool Insurance::walletBalanceIsSet() const
{
    return m_WalletBalanceIsSet;
}

void Insurance::unsetWalletBalance()
{
    m_WalletBalanceIsSet = false;
}

}
}
}
}
